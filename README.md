# F042K6_USB
Sample code to create USB device on NUCLEO F042K6. Tested on "Ubuntu 20.04.1 LTS".

### Install mbed_cli
https://os.mbed.com/docs/mbed-os/v6.8/build-tools/install-and-set-up.html


### Install gcc-arm-none-eabi-6-2017-q2-update

```
wget https://developer.arm.com/-/media/Files/downloads/gnu-rm/6-2017q2/gcc-arm-none-eabi-6-2017-q2-update-linux.tar.bz2
tar xvf gcc-arm-none-eabi-6-2017-q2-update-linux.tar.bz2
```

### Install virtualenv and python2
```
sudo apt-get install virtualenv python2.7 curl
curl https://bootstrap.pypa.io/pip/2.7/get-pip.py --output get-pip.py
python2 get-pip.py
pip install virtualenv
python2 -m virtualenv py2
source py2/bin/activate
pip install mbed-cli==1.10.1 pyelftools jsonschema
mbed config -G ARM_PATH /path/gcc-arm-none-eabi-6-2017-q2-update/bin
```

### Download mbed and usb sample code
```
mkdir magicusb
cd 
hg clone https://os.mbed.com/users/mbed_official/code/mbed-sdk-tools/ tools
pip install -r ./tools/requirements.txt
git clone https://github.com/ARMmbed/mbed-dev
git clone https://github.com/chen17/F042K6_USB F042K6_USBDevice
mv F042K6_USBDevice/main.cpp .
```

### Start compile
```
mbed compile -m NUCLEO_F042K6 -t GCC_ARM
```
