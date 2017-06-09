/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package echoclient;

import java.io.*;
import java.net.*;
import java.util.*;

/**
 *
 * @author x450c1
 */
public class EchoClient {

    public static void main(String[] args)  {
		try {
			// this could be changed to an IP name or address other than the localhost
			Socket sock = new Socket("127.0.0.1",5575);
                        
                        PrintWriter pout = new PrintWriter(sock.getOutputStream(), true);
                        
                        Scanner scan = new Scanner(System.in);
                        String text = scan.nextLine();
                        
                        pout.println(text); 
                        
                        
                        InputStream in = sock.getInputStream();
                        BufferedReader bin = new BufferedReader(new InputStreamReader(in));

                        String line;
                        while( (line = bin.readLine()) != null)
                                System.out.println(line);

			sock.close();
		}
		catch (IOException ioe) {
				System.err.println(ioe);
		}
	}
}
