## Overview

`rename-net-if` is simplified version of `renameif` utility. It can be handy in mimimal handmade distros (where UDEV is missing) for establishing network interface naming.

NOTE: It requires root permission and renamed interface should be in DOWN state.

## Autoconf build

```
autoreconf --install
./configure
make
```

## Usage

```
rename-net-if ORIGINAL-INTERFACE-NAME NEW-INTERFACE-NAME
```

## Example 

```
rename-net-if $(ls /sys/bus/pci/devices/0000\:03\:00.0/net/) lan
```
