#/dev/patel

Linux pseudo-device to display a picture of everyone's favorite British actor

##Installation

First, install the `module-assistant` package:

```bash
sudo apt-get install module-assistant
```

Then, install the device:

```bash
sudo make install
```

To uninstall the device:

```bash
sudo make uninstall
```

##Usage

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

##Acknowledgements

I don't know Mr. Patel, but I'm a fan of his work and his convenient first name.