import wixData from "dix-data"
import { session } from "wix-storage"
import wixLocation from "wix-location"

$w("btnLogar").onClick(() => {
    login()
})

export function login(){
    let user = $w("#TbUser").value
    let pass = $w("#TbPass").value

    wixData.query("Usuarios")
    .eq("email", user)
    .find()
    .then((resultado) => {
        if(resultado.items.lenght > 0){
            if(resultado.items[0].senha === pass){
                session.setItem("usuario", JSON.stringify(resultado.items[0]))

                wixLocation.to("/pagina-exclusiva") //redireciona
            }
            else{
                $w("#txtErro").text = "Senha Inválida"
                $w("#txtErro").show()
            }
        }
        else{
            $w("#txtErro").text = "Email não encontrado"
            $w("#txtErro").show()
        }
    })
}