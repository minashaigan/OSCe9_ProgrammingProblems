/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package quoteserver;

import java.io.*;
import java.net.*;

/**
 *
 * @author x450c1
 */
public class QuoteServer {

    public static void main(String[] args)  {
		try {
			ServerSocket sock = new ServerSocket(6017);

			// now listen for connections
			while (true) {
				Socket client = sock.accept();
				// we have a connection
				
				PrintWriter pout = new PrintWriter(client.getOutputStream(), true);
				// write the Date to the socket
				pout.println("Your lucky color has faded.\n%\n");
                                pout.println("Your lucky number has been disconnected.\n%\n");
                                pout.println("Your true value depends entirely on what you are compared with.\n%\n");
                                pout.println("Your lucky number is 3552664958674928.  Watch for it everywhere.\n%\n");
                                

				// close the socket and resume listening for more connections
				client.close();
			}
		}
		catch (IOException ioe) {
				System.err.println(ioe);
		}
	}
    
}
