function criaUser(nome, email) { //funcao factory, retorna um objeto
    return {
      nome,
      email,
      exibeInfos() {
        return `${nome}, ${email}`
      }
    }
   }

   const newUser = criaUser('Rodrigo', 'r@r.com')
console.log(newUser)
console.log(newUser.exibeInfos())