# F042K6_USB
Sample code to create USB device on NUCLEO F042K6.

# install pyenv
# install python 2.7.15
# install gcc-arm-none-eabi-6-2017-q2-update
# install mercurial and git SCM

pip install virtualenv
python -m virtualenv .venv2
. .venv2/bin/activate

pip install mbed-cli==1.10.1 pyelftools jsonschema

mkdir test
cd test
hg clone https://os.mbed.com/users/mbed_official/code/mbed-sdk-tools/ tools
pip install -r ./tools/requirements.txt
git clone https://github.com/ARMmbed/mbed-dev

# create your main.cpp

mbed compile -m NUCLEO_F042K6 -t GCC_ARM
