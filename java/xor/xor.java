/* use a very simple xor cipher to encrypt a file with a key (or decrypt the file, xor is a symmetric operation) */

import java.nio.file.Files;
import java.nio.file.Paths;
import java.nio.file.Path;
import java.io.IOException;

public class xor {
    public static void main(String[] args) throws IOException {
        if (args.length != 2) {
            System.out.println("please provide a filename and a string as command-line arguments");
            System.exit(-1);
        }
        
        String PWD = System.getProperty("user.dir");
        
        Path plaintextPath = Paths.get(PWD + "/" + args[0]); 
        Path ciphertextPath = Paths.get(PWD + "/result.txt");

        if(Files.notExists(plaintextPath)) {
            System.out.println("the file " + args[1] + " is not found");
            System.exit(-1);
        }

        byte[] plaintext = Files.readAllBytes(plaintextPath);
        byte[] key = args[1].getBytes();
        byte[] ciphertext = new byte[plaintext.length];

        for (int i = 0; i < plaintext.length; i++) {
            ciphertext[i] = (byte) (plaintext[i] ^ ciphertext[i%key.length]);
        }
        if (Files.notExists(ciphertextPath)) {
            Files.createFile(ciphertextPath);  
        }
        Files.write(ciphertextPath, ciphertext);
    }
}
