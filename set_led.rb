require 'serialport'

class Focus
  def initialize
    device = Dir.glob("/dev/cu.usbmodemCkbio*")[0]
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

LED_COUNT = 64

focus = Focus.new

def each_led
  return enum_for(:each_led) unless block_given?
  (0...LED_COUNT).each do |i|
    yield i
  end
end


each_led do |i|
  focus.command('led.set', i, 255, 255, 255)
  sleep 0.02
  focus.command('led.unset', i)
end
focus.command('led.unset-all')

