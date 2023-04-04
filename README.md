[![C/C++ CI](https://github.com/edpfacom/libfacom/actions/workflows/c-cpp.yml/badge.svg)](https://github.com/edpfacom/libfacom/actions/workflows/c-cpp.yml)

# para clonar o repositório

## preparação da chave de acesso
1. crie um repositório novo (repositories -> new )
2. crie a chave no seu terminal local (ssh-keygen -t ed25519)
3. copie a chave (cat ~/.ssh/id_ed25519.pub)
4. adicione a chave no repositório novo (settings -> Deploy keys -> add deploy key)

## comandos para clonar o repositório
```
git clone --bare git@github.com:edpfacom/libfacom.git
cd libfacom.git
git push --mirror <URL DO SSH DO NOVO REPOSITORIO. TEM QUE COMECAR COM GIT>
cd ..
rm -Rf libfacom.git
```


pronto! agora vc tem um novo repositório clonado no git. Para baixar o repositório 

```
git clone <URL DO SSH DO NOVO REPOSITORIO. TEM QUE COMECAR COM GIT>
```

## comandos para compilar

```
aclocal
autoreconf --install
./configure
make
make check
```
