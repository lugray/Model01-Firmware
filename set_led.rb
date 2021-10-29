require_relative 'focus'

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
focus.command('led.value', 50)
focus.command('led.setrc', 0, 2, 255, 255, 255)
sleep 2
focus.command('led.unset-all')

