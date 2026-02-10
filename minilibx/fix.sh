#!/bin/bash
grep -o "mlx_[a-z_]*" mlx_xpm.c | sort -u | while read func; do
    if ! grep -q "$func" mlx_int.h; then
        echo "MISSING in mlx_int.h: $func"
        # Try to find its definition
        if grep -l "$func" *.c | grep -v mlx_xpm.c; then
            file=$(grep -l "$func" *.c | grep -v mlx_xpm.c | head -1)
            sig=$(grep -A1 "^[a-z].*$func" "$file" 2>/dev/null | head -2 | tr '\n' ' ' | sed 's/{.*//' | xargs)
            if [ -n "$sig" ]; then
                echo "  Should be: $sig;"
            fi
        fi
    fi
done