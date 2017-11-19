#!/usr/bin/tclsh

proc srv {channel clientaddr clientport} {
   puts "Connection from $clientaddr registered"
   puts $channel [clock format [clock seconds]]
   close $channel
}

socket -server srv 44100
puts "Listening"
vwait forever
