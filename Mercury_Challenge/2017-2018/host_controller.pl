#udpserver.pl

#use declarations
use strict;
use diagnostics;
use warnings;
use IO::Socket::INET;
use Socket;
use Sys::Hostname;

#global vars

#set
my ($socket, $received_data);
my ($peeraddress, $peerport);

#create socket
$socket = new IO::Socket::INET (
LocalPort => "", #we don't know this yet
Proto => "udp",
);
#listen for port activity
while(){
    if($socket->recv($recieved_data,1024)){
        $peer_address = $socket->peerhost();
        $peer_port = $socket->peerport();
        while(1){
            $socket->recv($recieved_data, 1024);
            print "$recieved_data\n";
            
        }
    }
}