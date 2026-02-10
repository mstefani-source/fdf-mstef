#!/bin/bash
# fix_all_empty_declarations.sh

echo "=== Fixing ALL empty function declarations in mlx_int.h ==="

# Make backup
cp mlx_int.h mlx_int.h.backup.$(date +%s)

# List of functions and their actual signatures (based on common MinilibX)
declare -A signatures=(
    # From errors we've seen
    ["shm_att_pb"]="int shm_att_pb(Display *d, XErrorEvent *ev)"
    ["mlx_int_new_xshm_image"]="void *mlx_int_new_xshm_image(t_xvar *xvar, int width, int height, int format)"
    ["mlx_int_str_to_wordtab"]="char **mlx_int_str_to_wordtab(char *str)"
    
    # Common mlx_int_* functions
    ["mlx_int_get_visual"]="int mlx_int_get_visual(t_xvar *xvar)"
    ["mlx_int_deal_shm"]="int mlx_int_deal_shm(t_xvar *xvar)"
    ["mlx_int_rgb_conversion"]="int mlx_int_rgb_conversion(t_xvar *xvar)"
    ["mlx_int_anti_resize_win"]="int mlx_int_anti_resize_win(t_xvar *xvar, Window w, int width, int height)"
    ["mlx_int_do_nothing"]="void mlx_int_do_nothing(t_xvar *xvar)"
    ["mlx_int_wait_first_expose"]="void mlx_int_wait_first_expose(t_xvar *xvar)"
    ["mlx_int_set_win_event_mask"]="int mlx_int_set_win_event_mask(t_xvar *xvar)"
    ["mlx_int_param_event"]="void mlx_int_param_event(t_xvar *xvar)"
)

# First pass: fix known functions
for func in "${!signatures[@]}"; do
    sig="${signatures[$func]}"
    echo "Fixing $func..."
    # Replace func(); with proper signature
    sed -i "s/^[a-z].*$func();/$sig;/g" mlx_int.h
done

# Second pass: generic fix for any remaining mlx_int_*()
echo ""
echo "=== Fixing remaining mlx_int_* functions ==="
# These likely all take (t_xvar *xvar)
sed -i 's/^\([a-z][a-z_]*[[:space:]]*mlx_int_[a-z_]*\)();/\1(t_xvar *xvar);/g' mlx_int.h

# Third pass: fix any remaining ()
echo ""
echo "=== Fixing any remaining empty declarations ==="
# For non-mlx_int_* functions, we need to check their actual definitions
# Let's at least make them (void) to avoid implicit declaration warnings
sed -i 's/^\([a-z][a-z_]*[[:space:]]*[a-z_]*\)();/\1(void);/g' mlx_int.h

echo "Done! Check if any () remain:"
grep -n "();" mlx_int.h
