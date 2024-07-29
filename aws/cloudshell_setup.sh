echo "Setting up cloudshell environment"

if [ "$EUID" -ne 0 ]
  then echo "Please run as root using sudo"
  exit
fi

yum install gcc-c++
yum install libcurl-devel
yum install cmake
yum install ninja-build

# Install vcpkg
pushd .
mkdir /home/vcpkg
chown cloudshell-user /home/vcpkg
cd /home/vcpkg
git clone https://github.com/microsoft/vcpkg.git
cd vcpkg && ./bootstrap-vcpkg.sh
export VCPKG_ROOT=/home/vcpkg/vcpkg
export PATH=$VCPKG_ROOT:$PATH
popd


