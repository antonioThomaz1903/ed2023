[![C/C++ CI](https://github.com/edpfacom/libfacom/actions/workflows/c-cpp.yml/badge.svg)](https://github.com/edpfacom/libfacom/actions/workflows/c-cpp.yml)

# para atualizar as infos com o repositorio do professor

1. baixe seu repositorio
```
git clone <seu repositorio.git>
```
2. adicione o repositorio do professor na sua área
```
cd <seu diretorio>
git remote add professor git@github.com:edpfacom/libfacom.git
git config pull.rebase false
git pull professor main
git push origin main
```
 pronto agora basta fazer o seu código

# para clonar o repositório


## preparação da chave de acesso
1. crie um repositório novo (repositories -> new )
2. crie a chave no seu terminal local 
```
ssh-keygen -t ed25519
```
3. adicione a chave na maquina local 
```
exec ssh-agent bash
ssh-add ~/.ssh/id_ed25519
```

4. copie a chave (cat ~/.ssh/id_ed25519.pub)
5. adicione a chave no repositório novo (settings -> Deploy keys -> add deploy key). Coloque permissão de `writing` como verdadeiro

6. verifique se a conexão está funcional
```
ssh git@github.com 
```
caso apareceça `Hi <SEU REPOSITORIO>! You've successfully authenticated, but GitHub does not provide shell access.` sua chave esta funcionando

Caso dê errado apague as chaves anteriores ~/.ssh/id_* limpe o ssh-add
```
rm ~/.ssh/id_*
ssh-add -D
```
 e repita os passos novamente

## comandos para clonar o repositório (modo principal)
```
git clone git@github.com:edpfacom/libfacom.git
cd libfacom
git remote rename origin professor
git remote add origin git@github.com:<SEU REPOSITORIO>
git branch -M main
git push -u origin main
```



# comandos para compilar

```
aclocal
autoreconf --install
./configure
make
make check
```

# para incluir um novo algoritmo

1. crie o teste dentro de tests/test_nova_funcionalidade.c
2. adicione o arquivo criado em tests/Makefile.am (somente caso seja criado um novo arquivo de teste)
3. adicione as interfaces das funções em src/facom.h
4. crie o código fonte da funcionalidade em src/nova_funcionalidade.c
5. adicione o arquivo criado em src/Makefile.am (somente caso seja criado um novo arquivo com funcionalidade)


Pronto! agora basta dar um make e make check para verificar se o código está funcional

# para incluir uma nova função dentro de um algoritmo

1. altere o caso de teste em testes/test_heap.c
2. adicione as interfaces em src/facom.c
3. crie o codigo fonte da função em src/heap.c
4. make
5. make check



