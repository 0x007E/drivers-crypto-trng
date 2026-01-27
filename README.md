[![Version: 1.0 Release](https://img.shields.io/badge/Version-1.0%20Release-green.svg)](https://github.com/0x007e/drivers-crypto-trng) ![Build](https://github.com/0x007e/drivers-crypto-trng/actions/workflows/release.yml/badge.svg) [![License GPLv3](https://img.shields.io/badge/License-GPLv3-lightgrey)](https://www.gnu.org/licenses/gpl-3.0.html)

# `TRNG Crypto Driver`

This hardware abstracted driver can be used to interact with a external [ring-oscillator](#additional-information) circutit or any other random bit generator. The hardware layer is fully abstract an can be switched between different plattforms.

## File Structure

![File Structure](https://0x007e.github.io/drivers-crypto-trng/trng_8c__incl.png)

```
drivers/
└── crypto/
    └── trng/
        ├── trng.c
        └── trng.h
```

## Downloads

The library can be downloaded (`zip` or `tar`), cloned or used as submodule in a project.

| Type      | File               | Description              |
|:---------:|:------------------:|:-------------------------|
| Library   | [zip](https://github.com/0x007E/drivers-crypto-trng/releases/latest/download/library.zip) / [tar](https://github.com/0x007E/drivers-crypto-trng/releases/latest/download/library.tar.gz) | TRNG crypto library |

### Using with `git clone`

``` bash
mkdir -p ./drivers/crypto/
git clone https://github.com/0x007E/drivers-crypto-trng.git
mv ./drivers/crypto/drivers-crypto-trng ./drivers/crypto/trng
```

### Using as `git submodule`

``` bash
git submodule add https://github.com/0x007E/drivers-crypto-trng.git  drivers/crypto/trng
```

## Programming

``` c
#include "../lib/drivers/crypto/trng/trng.h"

// Continously pin status readin (e.g. through timer)
ISR(...)
{
    // ... Insert pin status (HIGH/LOW)
	trng_next_bit(...);
}

int main(void)
{
    // Pin Setup for TRNG

    // Timer Setup for TRNG

	trng_init();

    while(1)
    {
        if(trng_buffer_status() == TRNG_Buffer_Full)
		{
			volatile unsigned char *trng_numbers = trng_buffer();
			
			for (unsigned char i=0; i < TRNG_BUFFER_SIZE; i++)
			{
				// Output -> *(trng_numbers++) 
			}
			trng_reset();
		}
    }
}
```

# Additional Information

| Type       | Link               | Description              |
|:----------:|:------------------:|:-------------------------|
| Ring-Oscillator | [pdf](https://github.com/0x007E/vlt/releases/latest/download/schematic.pdf) | Ring-Oscillator circuit with NAND and XOR |

---

R. GAECHTER