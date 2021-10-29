require 'serialport'

class Focus
  def initialize
    device = Dir.glob("/dev/cu.usbmodemkbio*")[0]
    raise "Keyboard not connected" unless device
    @serial = SerialPort.new(device, 9600)
  end

  def command(*parts)
    @serial.write("#{parts.map(&:to_s).join(" ")}\n")
    response
  end

  def response
    lines = []
    until (line = @serial.readline.chomp) == "."
      lines << line
    end
    lines
  end
end
