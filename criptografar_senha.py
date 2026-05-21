from cryptography.fernet import Fernet

# Gera a chave e salva no arquivo key.key
key = Fernet.generate_key()
with open("key.key", "wb") as key_file:
    key_file.write(key)

fernet = Fernet(key)

# Sua senha original
senha_plana = "12345678"
senha_criptografada = fernet.encrypt(senha_plana.encode()).decode()

print("\nCole esta senha criptografada no seu config.ini:")
print(senha_criptografada)
