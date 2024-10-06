import random
import math
def coprime(phi):
    while True:
        x = random.randint(2,phi - 1)
        if math.gcd(x,phi) == 1:
            return x
        
def mod_inverse(e, phi):
    for i in range (1, phi):
        if (e*i) % phi == 1:
            return i
    return -1
    
def rsa_key_generation(p, q):
    n = p *q
    phi = (p-1) * (q-1)

    e = coprime(phi)

    d = mod_inverse(e, phi)

    # return (e,n), (d,n)
    return (79, n), (1019 , n)

def bigmod(m, e, n):
    if e == 1 :
        return m % n
    if e == 0:
        return 1
    if e % 2 == 0:
        half_cipher = (bigmod(m, e//2, n)) % n
        return (half_cipher * half_cipher) % n
    else:
        a = m % n
        b = (bigmod(m, e-1, n)) % n
        return (a * b) % n

def rsa_encrypt_block(plaintext, public_key, block_size):
    e, n = public_key

    blocks = [plaintext[i:i+block_size] for i in range(0,len(plaintext),block_size)]
    ciphertext = []
    for block in blocks:
        m = int(block)
        ciphertext.append(bigmod(m,e,n))
    return ciphertext

def rsa_decrypt_block(ciphertext, private_key, block_size):
    d, n = private_key

    decrypted_blocks = []

    for c in ciphertext:
        m = bigmod(c, d, n)
        decrypted_blocks.append(f'{m:0{block_size}d}')
    return ''.join(decrypted_blocks)

if __name__ == "__main__":

    p = 47 
    q = 71
    plaintext = "6882326879666683"
    public_key, private_key = rsa_key_generation(p, q)
    block_size = 3

    print(f'Private key : {private_key}')
    print(f'Public key : {public_key}')

    ciphertext = rsa_encrypt_block(plaintext, public_key, block_size)
    joined_ciphertext = ''.join(str(c) for c in ciphertext)
    print(f'Cipher :  {joined_ciphertext}')


    decrypted_msg = rsa_decrypt_block(ciphertext, private_key , block_size)
    print(f' Decipher : {decrypted_msg}')
    print(f'Original : {plaintext}')