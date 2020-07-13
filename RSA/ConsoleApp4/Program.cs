using System;
using System.Security.Cryptography;
using System.Text;

namespace RSA
{
    class Program
    {
        static void Main(string[] args)
        {

            var cryptoServiceProvider = new RSACryptoServiceProvider(2048);
            var privateKey = cryptoServiceProvider.ExportParameters(true); //Generating a private key
            var publicKey = cryptoServiceProvider.ExportParameters(false); //Generating a public key
            string publicKeyString = GetKeyString(publicKey);
            string privateKeyString = GetKeyString(privateKey);

            Console.WriteLine("PUBLIC KEY: ");
            Console.WriteLine(publicKeyString);
            Console.WriteLine("-------------------------------------------");

            Console.WriteLine("PRIVATE KEY: ");
            Console.WriteLine(privateKeyString);
            Console.WriteLine("-------------------------------------------");

            string textToEncrypt = StringGen();
            Console.WriteLine("TEXT FOR ENCRYPTING: ");
            Console.WriteLine(textToEncrypt);
            Console.WriteLine("-------------------------------------------");

            string encryptedText = Encrypt(textToEncrypt, publicKeyString); //Encrypting with public key
            Console.WriteLine("ENCRYPTED TEXT: ");
            Console.WriteLine(encryptedText);
            Console.WriteLine("-------------------------------------------");

            string decryptedText = Decrypt(encryptedText, privateKeyString); //Decrypting with private key

            Console.WriteLine("DECRYPTED TEXT: ");
            Console.WriteLine(decryptedText);

        }

        public static string GetKeyString(RSAParameters publicKey)
        {

            var stringWriter = new System.IO.StringWriter();
            var xmlSerializer = new System.Xml.Serialization.XmlSerializer(typeof(RSAParameters));
            xmlSerializer.Serialize(stringWriter, publicKey);
            return stringWriter.ToString();
        }

        public static string Encrypt(string textToEncrypt, string publicKeyString)
        {
            var bytesToEncrypt = Encoding.UTF8.GetBytes(textToEncrypt);

            using (var rsa = new RSACryptoServiceProvider(2048))
            {
                try
                {
                    rsa.FromXmlString(publicKeyString.ToString());
                    var encryptedData = rsa.Encrypt(bytesToEncrypt, true);
                    var base64Encrypted = Convert.ToBase64String(encryptedData);
                    return base64Encrypted;
                }
                finally
                {
                    rsa.PersistKeyInCsp = false;
                }
            }
        }

        public static string Decrypt(string textToDecrypt, string privateKeyString)
        {
            var bytesToDescrypt = Encoding.UTF8.GetBytes(textToDecrypt);

            using (var rsa = new RSACryptoServiceProvider(2048))
            {
                try
                {

                    // server decrypting data with private key                    
                    rsa.FromXmlString(privateKeyString);

                    var resultBytes = Convert.FromBase64String(textToDecrypt);
                    var decryptedBytes = rsa.Decrypt(resultBytes, true);
                    var decryptedData = Encoding.UTF8.GetString(decryptedBytes);
                    return decryptedData.ToString();
                }
                finally
                {
                    rsa.PersistKeyInCsp = false;
                }
            }
        }

        private static string StringGen()
        {
            string mess = "I wanna pass this subject already"; // Your plain text
            return mess.ToString();
        }
    }
}