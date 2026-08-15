# TraceIt

<p align="center">

![Linux](https://img.shields.io/badge/Linux-FCC624?style=for-the-badge&logo=linux&logoColor=black)


</p>

A lightweight Linux command-line utility written in **C** that inspects running processes through the **/proc** filesystem.

Instead of running multiple `ps -ef` commands and manually exploring `/proc`, simply run **TraceIt**, enter the process name, and inspect it instantly.


---

## Example Output

![TraceIt Demo](images/traceit-demo.png)
# Requirements

- Linux
- GCC
- GNU Make
- readline

Arch Linux:

```bash
sudo pacman -S gcc make readline
```

Ubuntu/Debian:

```bash
sudo apt install build-essential libreadline-dev
```

---

# Installation

Clone the repository:

```bash
git clone https://github.com/tracebyte8/traceit.git
cd traceit
```

Build the project:

```bash
make
```

---

# Run

Run directly from the project directory:

```bash
make run
```

or

```bash
./traceit
```


---

# License

This project is released under the MIT License.

---

Made with ❤️ using  **C**
