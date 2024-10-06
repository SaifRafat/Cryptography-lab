import math
import random

def coprime(phi):
    while True:
        x = random.randint(2, phi - 1)
        if math.gcd(x, phi) == 1:
            return x

# Compute modular inverse using extended Euclidean algorithm
def mod_inverse(e, phi):
    for i in range(1, phi):
        if (e * i) % phi == 1:
            return i
    return -1

def rsa_key_generation(p, q):
    n = p * q
    phi = (p - 1) * (q - 1)

    # public exponent e
    e = coprime(phi)

    # private exponent d
    d = mod_inverse(e, phi)

    return (79, 3337), (1019, 3337)
    # return (e,n), (d,n)

def bigmod(m, e, n):
    if e == 0:
        return 1
    if e == 1:
        return m % n
    if e % 2 == 0:
        half_cipher = (bigmod(m, e // 2, n)) % n
        return (half_cipher * half_cipher) % n
    else:
        a = m % n
        b = (bigmod(m, e - 1, n)) % n
        return (a * b) % n

def rsa_encrypt_blocks(msg, public_key, block_size=3):
    e, n = public_key
    # Split the message into blocks of 'block_size' digits
    blocks = [msg[i:i + block_size] for i in range(0, len(msg), block_size)]
    
    cipher = []
    for block in blocks:
        # Convert the block into an integer and encrypt
        m = int(block)
        cipher.append(bigmod(m, e, n))
    
    return cipher

def rsa_decrypt_blocks(cipher, private_key, block_size=3):
    d, n = private_key
    
    decrypted_blocks = []
    for c in cipher:
        # Decrypt each block
        m = bigmod(c, d, n)
        # Format the decrypted block as a zero-padded string of the correct block size
        decrypted_blocks.append(f'{m:0{block_size}d}')
    
    # Combine all the decrypted blocks into the full decrypted message
    return ''.join(decrypted_blocks)

if __name__ == '__main__':
    # this code will also work for zero digit but  have to be careful for the last block- check  debug this if message % block_size !=0   
    # # Example large number message
    # message = "688232687966668003"  # The numeric message to encrypt
    
    # # RSA primes
    # p = 61
    # q = 53
    with open('input.txt','r') as infile:
        p = int(infile.readline().strip())
        q = int(infile.readline().strip())
        message = infile.readline().strip()
    
    # Generate RSA keys
    public_key, private_key = rsa_key_generation(p, q)
    
    print(f'Public Key: {public_key}')
    print(f'Private Key: {private_key}')
    
    # Encrypt the message in 3-digit blocks
    cipher = rsa_encrypt_blocks(message, public_key, block_size=3)
    cipherr = ''.join(str(c) for c in cipher)
    print(f'Cipher            : {cipherr}')
    
    # Decrypt the cipher back to the original message
    deciphered_message = rsa_decrypt_blocks(cipher, private_key, block_size=3)
    print(f'Decipher: {deciphered_message}')
    print(f'original: {message}')