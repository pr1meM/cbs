# cb Script
---
## What is this?

cb Script is a tool, to automatically generate a pwntools python script, every pwn-ctf player needs. Instead of just writing the script by hand, you can just run the tool with some arguments and it provides you the simple python base script.

---
## How to use?
First compile the cbs file:
`gcc -o cbs cbs.c`

Then move the compiled file to `/usr/local/bin`. That makes sure that you can run the command `cbs` everywhere, without specifing its path.

Finally run cbs + arg1 + arg2. With the first argument, you specify the process binary. And with the second argument, you specify the offset, if necessary.
Example: `cbs challege 44` or just `cbs challenge`

---
## Leave a Star
If you find this tool useful, leave a star and feel free to contribute.

---
Author: M


