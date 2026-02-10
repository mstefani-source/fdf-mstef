#!/bin/bash
echo "=== Fixing all void pointer dereferences ==="

# mlx_int_get_line fixes
# Line 32: if ((pos2 = mlx_int_str_str(ptr+*pos,"\"",size-*pos))==-1)
sed -i '32s/mlx_int_str_str(ptr+\*pos,/mlx_int_str_str((char *)ptr + *pos,/' mlx_xpm.c

# Line 34: pos2 = mlx_int_str_str(ptr+*pos+pos2,"\"",size-*pos-pos2)+pos2;
sed -i '34s/mlx_int_str_str(ptr+\*pos+pos2,/mlx_int_str_str((char *)ptr + *pos + pos2,/' mlx_xpm.c

# Line 36: *(ptr+*pos+pos2) = 0;
sed -i '36s/\*(ptr+\*pos+pos2) = 0;/\*((char *)ptr + *pos + pos2) = 0;/g' mlx_xpm.c

# Line 37: *(ptr+*pos+pos2+1+pos3) = 0;
sed -i '37s/\*(ptr+\*pos+pos2+1+pos3) = 0;/\*((char *)ptr + *pos + pos2 + 1 + pos3) = 0;/g' mlx_xpm.c

# Line 38: return (ptr+*pos);
sed -i '38s/return (ptr+\*pos);/return ((char *)ptr + *pos);/g' mlx_xpm.c

# mlx_int_static_line fixes
# Line 47: ret = xpm_data[*pos];
sed -i '47s/ret = xpm_data\[\*pos\];/ret = ((char **)xpm_data)[*pos];/g' mlx_xpm.c

# Line 52: str = xpm_data[(*pos)++];
sed -i '52s/str = xpm_data\[(\*pos)\+\+\];/str = ((char **)xpm_data)[(*pos)++];/g' mlx_xpm.c

echo "Done!"
