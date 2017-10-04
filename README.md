# /dev/patel

Linux pseudo-device to display a picture of everyone's favorite British actor

## Installation

First, install the necessary packages:

```bash
sudo apt-get install make module-assistant linux-headers-`uname -r`
```

Then, install the device:

```bash
sudo make install
```

To uninstall the device:

```bash
sudo make uninstall
```

To install using [Vagrant](https://www.vagrantup.com/):

```bash
vagrant up && vagrant ssh
sudo make install
```

## Usage

```
$ cat /dev/patel
?PNG

IHDk?XT`PLTE????j?h?????q????ZC\?{Z?²?G.???????????`??|????????a??????ܟ????#tnn?
```

To see what the device is outputting:

```
$ cat /dev/patel > dev-patel.png
```

![Dev Patel](dev-patel.png)

## Acknowledgements

I don't know Mr. Patel, but I'm a fan of his work and his convenient first name.