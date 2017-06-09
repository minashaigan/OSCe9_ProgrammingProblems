/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package echoserver;

import java.io.*;
import java.net.*;

/**
 *
 * @author x450c1
 */
public class EchoServer {

    public static void main(String[] args)  {
		try {
			ServerSocket sock = new ServerSocket(5575);

			// now listen for connections
			while (true) {
				Socket client = sock.accept();
				// we have a connection
				
				PrintWriter pout = new PrintWriter(client.getOutputStream(), true);
				// write the Date to the socket
				InputStream in = client.getInputStream();
                                BufferedReader bin = new BufferedReader(new InputStreamReader(in));

                                String line;
                                while( (line = bin.readLine()) != null)
                                    pout.println(line);  
                                
                            
                                 

				// close the socket and resume listening for more connections
				client.close();
			}
		}
		catch (IOException ioe) {
				System.err.println(ioe);
		}
	}
    
    
}
