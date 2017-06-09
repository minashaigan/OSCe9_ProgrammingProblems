/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package haikuserver;

import java.io.*;
import java.net.*;

/**
 *
 * @author x450c1
 */
public class HaikuServer {

    private static final String[] haiku = { 
	" Winter is coming. \n Snow will be arriving soon. \n We should rake the leaves.",
	" Tired cat sleeps all night. \n He needs lots of rest for a \n Long day of napping.",
	" My homework is late. \n My dog ate it this morning. \n I sure like my dog.",
	" Hello World is the \n most famous computer code \n ever written in C",
	};
    
    public static void main(String[] args)  {
		try {
			ServerSocket sock = new ServerSocket(5575);

			// now listen for connections
			while (true) {
				Socket client = sock.accept();
				// we have a connection
				
				PrintWriter pout = new PrintWriter(client.getOutputStream(), true);
				// write the Date to the socket
				pout.println(haiku[(int)(java.lang.Math.random() * haiku.length)] );                              

				// close the socket and resume listening for more connections
				client.close();
			}
		}
		catch (IOException ioe) {
				System.err.println(ioe);
		}
	}
    
    
}
