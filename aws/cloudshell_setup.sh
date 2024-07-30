echo "Setting up cloudshell environment"

yes | sudo yum install clang
yes | sudo yum install perl
yes | sudo yum install libcurl-devel
yes | sudo yum install cmake
yes | sudo yum install ninja-build
yes | sudo yum install git

CUR_USER=`whoami`
# Install vcpkg
pushd .
sudo mkdir /home/vcpkg
sudo chown ${CUR_USER} /home/vcpkg
cd /home/vcpkg
git clone https://github.com/microsoft/vcpkg.git
cd vcpkg && ./bootstrap-vcpkg.sh
export VCPKG_ROOT=/home/vcpkg/vcpkg
export PATH=$VCPKG_ROOT:$PATH
popd

cmake --preset=default

