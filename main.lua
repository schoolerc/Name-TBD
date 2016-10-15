function sleep(s)
	local ntime = os.time()+s
	repeat until os.time()> ntime
end

wnd = Window.new ("Test", 200, 100, 800, 600)
wnd:set_pos (400, 0)
wnd:set_size (800, 100)

print('window size: ')
print (wnd:get_size ())

print ('window position: ')
print (wnd:get_pos ())

sleep(100)