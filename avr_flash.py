# This script creates .bin and .hex files from a given .c file and flashes the .hex file to a Microcontroller
import os
#MCU="atmega328p"
MCU="atmega328" # Arduino Uno
F_CPU=1600000 # 16MHz
CC="avr-gcc"
OBJCOPY="avr-objcopy"
CFLAGS=f"-std=c99 -Wall -g -Os -mmcu={MCU} -DF_CPU={F_CPU} -I."
TARGET="main_e"
SRCS="praktikum1_e.c"

# Create .bin and .hex files
def create():
    os.system(f"{CC} {CFLAGS} -o {TARGET}.bin {SRCS}")
    os.system(f"{OBJCOPY} -j .text -j .data -O ihex {TARGET}.bin {TARGET}.hex")
    print(f"{TARGET}.bin and {TARGET}.hex have been created")

# Flash .hex files to Microcontroller
def flash():
    os.system(f"avrdude -p {MCU} -c arduino -U flash:w:{TARGET}.hex:i -F -P /dev/ttyS4")
    print(f"{TARGET}.hex has been flashed to Microcontroller ({MCU})")

# Delete .bin and .hex files
def clean():
    os.system("rm -f *.bin *.hex")
    print(".bin and .hex files have been deleted")

def main():
    print("##################    AVR Flash Script    ##################")
    print("#")
    print("# Choose between the following actions; create, flash or clean")
    print("#")
    print("# 1 - Create: Creates .bin and .hex files")
    print("# 2 - Flash: Flashes .hex files to Microcontroller")
    print("# 3 - Clean: Deletes .bin and .hex files from current directory")
    result = input("# Input: ")
    if result == "1":
        create()
    elif result == "2":
        flash()
    elif result == "3":
        clean()
    else:
        print("Invalid input, please choose between 1, 2 or 3")

if __name__ == "__main__":
    main()
