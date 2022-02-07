#!/usr/bin/env ruby

require 'serialport'

class Focus
  def initialize
    device = Dir.glob("/dev/cu.usbmodemkbio*")[0]
    raise "Keyboard not connected" unless device
    @serial = SerialPort.new(device, 9600)
  end

  def command(*parts)
    # Split the write up into chunks because macOS can send things too fast (despite setting the baud rate???)
    "#{parts.map(&:to_s).join(" ")}\n".each_char.each_slice(10) do |slice|
      @serial.write(slice.join)
    end
    response
  end

  def response
    lines = []
    until (line = @serial.readline.chomp) == "."
      lines << line
    end
    lines
  end

  def run
    loop do
      puts command(readline.chomp)
    end
  end
end

Focus.new.run if __FILE__ == $0
