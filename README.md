# libasm

## Features

This library is made by assembly language.

It is included 6 functions that is basic and main function in C-language.

I write it with 64 bits ASM and the Intel syntax.

## Requirement
- gcc compiler
- nasm compiler

## Usage
Clone this repository:
```shell
git clone https://github.com/sakku-14/libasm
```

Generate library:
```shell
make
```

Check how it works:
```shell
make test
```

## Note

In this library, following functions are included:

- ft_strlen (based on manual of strlen)
- ft_strcpy (based on manual of strcpy)
- ft_strcmp (based on manual of strcmp)
- ft_write (based on manual of write)
- ft_read (based on manual of read)
- ft_strdup (based on manual of strdup)

Also set the errno when call syscalls.

## Author
- Yuki Sakuma
