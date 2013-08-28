42-toolkit	C Error Function
==========

# Preview

<p align="center" >
	<img src="https://raw.github.com/QuentinPerez/42-toolkit/master/doc/images/m_error.png" alt="m_error" title="m_error">
</p>

# Function
    - <code>m_error(const char *str_err, size_t ret_val)</code>
	- This function print str_err on <code>stderr</code> and return <code>ret_val</code>

    - <code>m_error_v(const char *str_err)</code>
	- This function print str_err on <code>stderr</code>

	- <code>m_error_infos(const char *infos)</code>
	- This function print infos on <code>stdout</code>

# Warning

You should add -DD_ERRORS_ON to CFLAGS or compile in debug with [Makefile]()

## License

42-toolkit is available under the [GNU General Public License, version 3](LICENSE).
