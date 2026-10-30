## Endiana-Jones

Single Header File which provides functions to handle conversion of Host Byte Order (Little-Endian ~ mostly, until you have a Motorola 68000 series) to Network Byte Order (Big-Endian) and vise versa.

### Usage:
- Single Header File implementation.
- Save and move the header file `endiana_jones.h` into your project directory.
- Include it into your C program and use the functions.
- Checkout [test.c](test.c) for an example.

### What is a Byte Order?

*(Simple and Straight version)* Byte Order: The way a Computer arranges bytes in computer memory.<br>

Basically two kinds:
- **Big-Endian**: The "Big end ~ First byte" (Most Significant Byte) is stored first.
- **Little-Endian**: The "Little end ~ Last byte" (Least Significant Byte) is stored first followed by other, just reverse of what big-endian was like.

Example: A you have (2-byte) integer in hex format: 0x1234 <br>
In a Big-Endian system it will be stored as: 0x1234 <br>
In a Little-Endian system it will be stores as: 0x3412

*(Story Time)*
Different COMPUTERs (systems) store and interpret Data (bytes) in sequential manner, basically two kinds -- **Big-Endian** and **Little-Endian**.

**So why does it even matter?**<br>
-> As long as your program runs on a single machine (your pc) it doesn't (wohoo), why? because the cpu reads and writes using its own native endianness. <br>
Most Computers nowadays use **Little-Endian** AKA `Host Byte Order`. Intel and AMD systems both uses "Little-Endian" while old systems like the Motorola 68k series uses "Big-Endian".

But things get a little interesting when the network (internet) is involved ~ basically internet protocols like (TCP/UDP) use **Big-Endian** AKA `Network Byte Order` (why? idk because they like it maybe) <br>
A lot of times when you're building packets you will need to make sure your Byte Order is correct cause you can't just build with "Little-Endian" for network and send it over. It has it's own interpreter ~ which expects a different order, this will result having different values and hence wrong port, annihilation and other errors.

### What does Endiana-Jones do?
You need to make sure your Byte Order isn't wrong when building packets or specifying, IP addresses, port numbers, etc etc. But how can you do this if you don't know what's your native Host Byte Order?

**Endiana-Jones** provides you with the necessary functions through which you pass the values (2-bytes only for now) to make it Big-Endian(Network Byte Order) or Little-Endian(Host Byet Order). The function will handle the conversion if it's required.

Currently supports:
- `hstontk(your_host_bytes)`: Host to Network (2-bytes) - Checks the current systems endianness, if it's Little-Endian then converts it into Big-Endian for network.
- `ntkohst(your_network_bytes)`: Network to Host (2-bytes) - Same functionality just vise versa, if the native system is Little-Endian then converts from Big-Endian to Little-Endian. <br>
If the system is Big-Endian then no conversion is made.

### Why did i build this?
Well i just started learning about networking and stuff, so came accross a awesome guide on Network Programming the ONE and ONLY [Beej's Guide to Network Programming](https://beej.us/guide/bgnet/html/split/index.html) <br>
This is where i encountered and learned about Byte Order and why it's important to take care of. <br>
I know these kind of functions to take care of all these stuffs are already present for C, but here i am not trying to create another super cool hyper tech `htons()` or something. I created this just as a personal project, out of curiosity, and to see whether i can do it or not ~ (these network stuffs are hard). <br>
This is not the perfect way to do it and isn't complete in all manner, i just made something out of my own understanding.
