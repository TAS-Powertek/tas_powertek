# Development of SPF21Y Tester

The /aws folder contains a code for an AWS lambda that can receive a request from SPF21Y Controller, parse it, and store the data into a AWS DynamoDB table before returning a response. 

## Pre-requisite
1. Amazon Linux Distro (easiest option - Use an AWS EC2 instance)
2. Install the following pre-requisites-
```
yes | sudo yum install clang
yes | sudo yum install perl
yes | sudo yum install libcurl-devel
yes | sudo yum install cmake
yes | sudo yum install ninja-build
yes | sudo yum install git
```
3. Install VCPKG-
```
cd ~
git clone https://github.com/microsoft/vcpkg.git
cd vcpkg && ./bootstrap-vcpkg.sh
export VCPKG_ROOT=~/vcpkg
export PATH=$VCPKG_ROOT:$PATH
```
Note: If the machine is restarted, you will need to issue the `export` commands again. Using `.bash_profile` is an exercise left for the reader.

## Clone TAS Powertek Git repository
```
cd ~
git clone https://github.com/TAS-Powertek/tas_powertek.git
cd tas_powertek
cd aws
```
This should set the current working directory as the `aws` folder.

## Modify the username and password
The checked in code to github should NOT contain the username and password. Instead, after cloning the github, open the `spf21ytester.cpp` file, and set appropriate values for-
```
static constexpr std::string_view kUserName = "";
static constexpr std::string_view kPassword = "";
```

## Building from source code
1. Download all pre-requisite libraries/dependencies (this might take long for the first time)
```
cmake --preset=default
```

2. Build the spf21ytester code-
```
cmake --build out
```

3. Create the lambda zip file-
```
cmake --build out --target aws-lambda-package-spf21ytester
```

## Deploying
1. Download the zip file from `~/tas_powertek/aws/out/spf21ytester.zip` to local file system (if you use VS Code - right click and download file. Or use `scp`)
2. Go to the AWS Console. Search and open the "Lambda" page, and find the "spf21ytester" lambda
3. Click on "Upload from" and then click "zip file". 
4. Select the zip file, and wait for it to be uploaded. If successful, you should see a "green ribbon" at the top of the page.

## Debugging
1. On the AWS Lambda page for "spf21ytester" click on "Monitor"
2. Click on "View Cloudwatch logs"
3. Click on any of the "log streams" to see one of the logs. Note that the logs from the code start with something like "I1016 04:51:20.744629 8 spf21ytester.cpp"
4. You can also click on "Start Tailing" to see the latest logs as they arrive.

## HTTP Endpoint
By default AWS Lambda only offers an HTTPS endpoint. To expose an HTTP endpoint, I used cloudfront (AWS Console -> Cloudfront). The cloudfront config is:
1. View policy: HTTP and HTTPS
2. Origin policy: Lambda with HTTPS


