# Libft

## Building your own C library

### Usage:
- `make`
- `cc <your C file here> -L. -lft`

Explaining the flags:
 - L.: Tells the linker to look for libraries in the current directory (.);
 - lft: Tells the linker to link against the library named libft.a. The linker will automatically prepend lib and append .a (or .so on some systems) to this name.