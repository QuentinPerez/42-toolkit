42-toolkit	C Crypto Function
==========

## Function

	- uf_crypto_xor(void *data, const char *key, ui data_size)
	 /* This function use xor algorithm for encrypt / decrypt data */

	- uf_crypto_rot5(char *str)
	 /* ROT algorithm which encrypt / decrypt the numeric digits of a string */

	- uf_crypto_rot13(char *str)
	 /* ROT algorithm which encrypt / decrypt the alphabetics characters of a string */

	- uf_crypto_rot18(char *str)
	 /* A combinaison of ROT5 and ROT13 */

	- uf_crypto_rot47(char *str)
	 /* ROT47 is a variant of ROT13 which also treats numbers and commons symbols */

## How to use ?

You can see example [here](https://github.com/QuentinPerez/42-toolkit/tree/master/examples/libc/f_crypto).

## License

42-toolkit is available under the [GNU General Public License, version 3](LICENSE).
