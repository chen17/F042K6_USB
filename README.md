# F042K6_USB
Sample code to create USB device on NUCLEO F042K6. Tested on "Ubuntu 20.04.1 LTS" and MacOS "11.2.3".

### Install virtualenv, python2, mbed and gcc-arm
```
sudo apt-get install virtualenv python2.7 curl
curl https://bootstrap.pypa.io/pip/2.7/get-pip.py --output get-pip.py
python2 get-pip.py
pip install virtualenv 
python2 -m virtualenv py2
source py2/bin/activate
pip install mbed-cli==1.10.1 pyelftools jsonschema Mercurial

Linux:
wget https://developer.arm.com/-/media/Files/downloads/gnu-rm/6-2017q2/gcc-arm-none-eabi-6-2017-q2-update-linux.tar.bz2

Mac:
wget https://developer.arm.com/-/media/Files/downloads/gnu-rm/6-2017q2/gcc-arm-none-eabi-6-2017-q2-update-mac.tar.bz2
tar xvf gcc-arm-none-eabi-6-2017-q2-update-linux.tar.bz2
mbed config -G ARM_PATH `pwd`/gcc-arm-none-eabi-6-2017-q2-update/bin
```

### Download mbed and usb sample code
```
mkdir magicusb
cd magicusb
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
