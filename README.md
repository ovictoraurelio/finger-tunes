# Finger tunes

Finger Tunes is a device and application developed for the Interface Hardware Software discipline at CIn UFPE. This repo contains a arduino project to Finger Tunes.

This project has two majors goals:
  - Use of a FPGA 
  - Create a driver for a Linux computer

So on arduino we just read the data of touch and send to FPGA.

Projects related to this:
- Linux application: [app-finger-tunes]
- Driver: [driver-finger-tunes]
- FPGA: [fpga-finger-tunes]


## The hardware

Developed with a Arduino, we built gloves to detect fingers touch and produce tunes. 

## Sensors 

Basically we create a simple circuit thats closed on touch.
Using two signals (+ and -) and a keys of a older and broken keyboard

## Comunication with FPGA

We basically send an array to the FPGA, in each position cointains 1 if the finger is pressed and 0 for an unpressed finger.

## Contributing

Pull requests and stars are always welcome. For bugs and feature requests, [please create an issue](https://github.com/ovictoraurelio/finger-tunes/issues)

## Authors

  [Almir Cunha]

  [Erik Zambom]

  [Nathan Martins]

  [Victor Aurélio]

  [Vitor Martins]

[Almir Cunha]: <http://cin.ufpe.br/~amcj2>
[Nathan Martins]: <http://cin.ufpe.br/~nmf2>
[Erik Zambom]: <http://cin.ufpe.br/~egz>
[Vitor Martins]: <http://cin.ufpe.br/~vmam>
[Victor Aurélio]: <http://victoraurelio.com>

[app-finger-tunes]: <https://github.com/almdac/app-finger-tunes>
[driver-finger-tunes]: <https://github.com/nmf2/driver-finger-tunes>
[fpga-finger-tunes]: <http://victoraurelio.com>
