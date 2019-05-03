#udpserver.pl

#use declarations
use strict;
use diagnostics;
use warnings; 
use IO::Socket::INET; #https://www.thegeekstuff.com/2010/07/perl-tcp-udp-socket-programming/
use Sys::Hostname;
use Tk; #http://search.cpan.org/dist/Tk-804.027/pod/UserGuide.pod
$| = 1; #https://perl.plover.com/FAQs/Buffering.html
#http://ask-leo.com/how_do_i_turn_off_keyboard_repeat.html

#global vars
my ($socket, $received_data);
my ($peer_address, $peer_port);

#subroutine connect
sub udp_connect{
    $socket = new IO:Socket::INET(
        PeerAddr => '',
        Proto    => 'udp'
        );
}
#read from socket
sub read_udp{
    my $heart_beat = <$socket>;
    print "$heart_beat";
}

#master loop
udp_connect();
my $mw = MainWindow->new;
#detect key inputs
$mw->bind('<KeyRelease>' => sub{
                                $socket->send("released");
                                });
$mw->bind('<KeyPress-w>' => sub{
                                $socket->send("w");
                                });
$mw->bind('<KeyPress-a>' => sub{
                                $socket->send("a");
                                });
$mw->bind('<KeyPress-s>' => sub{
                                $socket->send("s");
                                });
$mw->bind('<KeyPress-d>' => sub{
                                $socket->send("d");
                                });
$mw->bind('<KeyPress-W>' => sub{
                                $socket->send("1");
                                });
$mw->bind('<KeyPress-A>' => sub{
                                $socket->send("2");
                                });
$mw->bind('<KeyPress-S>' => sub{
                                $socket->send("3");
                                });
$mw->bind('<KeyPress-D>' => sub{
                                $socket->send("4");
                                });
$mw->bind('<KeyPress-Q>' => sub{
                                $socket->send("5");
                                });
$mw->bind('<KeyPress-E>' => sub{
                                $socket->send("6");
                                });
$mw->bind('<KeyPress-R>' => sub{
                                $socket->send("7");
                                });
$mw->bind('<KeyPress-F>' => sub{
                                $socket->send("8");
                                });

    
MainLoop;