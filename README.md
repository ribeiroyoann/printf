# ft_printf

### Summary
My implementation of libc's `printf`.  
The project is complicated as the number of parameters is indefinite. We use variadic arguments in this case.  
* Manage the following conversions: `s`, `S`, `p`, `d`, `D`, `i`, `o`, `O`, `u`, `U`, `x`, `X`, `c` & `C`
* Manage `%%`
* Manage the flags `#`, `0`, `-`, `+` & `space`
* Manage the minimum field-width
* Manage the precision
* Manage the flags `hh`, `h`, `l`, `ll`, `j`, & `z`.
  
