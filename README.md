# Operating System Concepts 10ed.

## Book online resources

- https://www.os-book.com/OS10/

## Aboud kernel programming exercise

I tried to use docker linux container in my mac to practice kernel programming, but it can't.

[See this docker container info.](https://www.docker.com/resources/what-container/)
Containers share their kernel with host Operating system, so linux kernel programming cannot achive by linux container on macos.

So use Virtual Machines, I used UTM VM in this practice(cause i'm using arm64 macos)

1. Download [UTM](https://mac.getutm.app/) and install
2. Download [Ubuntu Iso](https://ubuntu.com/download/server/arm)
3. Make VM with UTM and downloaded Ubuntu iso image.
4. To use VM at my host os terminal, set a network port-forwarding settng in VM.
5. Go to VM setting, go to network tap, change to VLAN, set port-forwarding.
6. Connect to VM in host os by using `ssh -p $HOST_SSH_PORT ($VM_USERNAME)@localhost`
