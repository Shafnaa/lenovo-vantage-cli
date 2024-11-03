# Lenovo Vantage CLI for Linux
This CLI tools helps you to provide [Lenovo Vantage](https://www.lenovo.com/us/en/software/vantage) in GNU/Linux operating system. This project is inspired by [@niizam](https://github.com/niizam) at his [Lenovo Vantage for Linux](https://github.com/niizam/vantage) project. But I figured that I wanted the CLI version of it. So, I try to create my own version in c.

## 🚀 Features
* Conservation Mode (Limit battery charge to prolong its life)
* Thermal/Fan Mode (Quiet, balanced and performance modes)
* FN Key Lock

## 📓 How it works
So basically, the settings for those things are saved in a file under the ```/sys/bus/platform/devices/VPC2004:00/``` and in order to change the settings we just need to edit the file. We can edit them just by going to the file and manually edit them. But it will require us to use a sudo command each time we want to update it. This CLI tool provides a shortcut to achieve the same goal.

## 💻 Installation  

First of all, you need to clone the repository with this command:

```bash
git clone https://github.com/Shafnaa/lenovo-vantage-cli.git
cd lenovo-vantage-cli
```

Then you can easily run this command:

```bash
sudo make install
```

Run "Lenovo Vantage" from your applications list.

## 🔨 Usage

There are 4 main commands:

```bash
vantage-cli status
sudo vantage-cli conservation
sudo vantage-cli fan
sudo vantage-cli fnlock
```

You can always use ```-h``` or ```--help``` to see what are the available options. To change the settings you will need sudo command in front. Passing the command without further argument will toggle the selected settings. 


## ♨️ Uninstall
To uninstall Lenovo Vantage, you can just run this:

```bash
sudo make uninstall
```
---