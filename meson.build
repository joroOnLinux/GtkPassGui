project('pass-gui', 
		['c','cpp'],
		default_options : ['buildtype=debugoptimized', 'c_std=c99', 'cpp_std=c++11'])
gtkdep = dependency('gtk+-3.0')
gtkmmdep = dependency('gtkmm-3.0')
src=['main.cc','examplewindow.cc']
executable('pass-gui', src,dependencies : [gtkdep,gtkmmdep])

