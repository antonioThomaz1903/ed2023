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

# comandos para compilar

```
aclocal
autoreconf --install
./configure
make
make check
```

# para incluir uma nova funcionalidade

1. crie o teste dentro de tests/test_nova_funcionalidade.c
2. adicione o arquivo criado em tests/Makefile.am (somente caso seja criado um novo arquivo de teste)
3. adicione as interfaces das funções em src/facom.h
4. crie o código fonte da funcionalidae em src/nova_funcionalidade.c
5. adicione o arquivo criado em src/Makefile.am (somente caso seja criado um novo arquivo com funcionalidade)


Pronto! agora basta dar um make e make check para verificar se o código está funcional
