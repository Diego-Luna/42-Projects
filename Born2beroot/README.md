# Notas de Born2berrot

* [English](#English)
* [Español](#Español)
------------------
------------------

## Español

### tty

* para saver que estamos conectados ```tty```

### hostnamectl

* ver informacion: ```hostnamectl```
* para cambiar el nombre del host: ```hostnamectl set-hostname [name]```
* * Reinicie su máquina virtual.
* * sudo nano /etc/hosts

### Usuarios
* ver los usuarios: ```cat /etc/passwd```
* ver los usuarios: ```getent passwd```
* nuevo usuario: ```sudo adduser [name]```
* borrar usuario: ```sudo userdel -r [name]```
* agregar usuario a un grupo: ```sudo usermod -aG [group_name] [user_name]```
#### contraseña
* * para ver politicas ```chage -l [user]```
* * ver o modificar politica de contraseñas ```sudo nano /etc/pam.d/common-password```


### Grupos
* ver los grupos: ```getent group```
* borrar grupos: ```sudo groupdel [name]```
* ver los usuarios que pertenecen: ```getent group ssh```

### sistem

* Puerto SSH: ```sudo grep Port /etc/ssh/sshd_config```
* Checar el sistema operativo : ```head -n 2 /etc/os-release```
* Particion del discod e la maquina virtual: ```lsblk```
#### Sudo
* * Comprovar sudo: ```su -```
* * ver el /etc/sudoers: ```sudo vim /etc/sudoers```

### ports
* ver los puertos  ```ss -tunlp```

### apparmor

* Checar apparmor
* * primo en sudo ```sudo su -```
* * revisamos apparmor ```/usr/sbin/aa-status```

### cron

* Status : ```sudo systemctl status cron```
* Reiniciar cron : ```sudo systemctl restart cron```
* Acceder a el script de cron : ```sudo crontab -u root -e```

----
### Defense con respuestas

1.**¿Por qué elegí Debian?**

Más fácil de instalar y configurar, por lo que es mejor para servidores personales.

2.**¿Diferencia entre Debian y CentOS?**

Debian es mucho más fácil de actualizar que CentOS cuando se lanza una nueva versión. Debian es más fácil de usar y admite muchas bibliotecas, sistemas de archivos y arquitectura. También tiene más opciones de personalización. Si es una empresa más grande, CentOS ofrece más funciones empresariales y un excelente soporte para el software empresarial.

3.**¿Qué es una Máquina Virtual?**

Es un recurso que utiliza software en lugar de una computadora física para ejecutar programas o aplicaciones. Cada VM tiene su propio sistema operativo y funciones por separado, por lo que puede tener más de una VM por máquina. Se puede utilizar para probar aplicaciones en un entorno seguro y separado. Funciona mediante el uso de software para simular hardware virtual y ejecutarse en una máquina host.

4.**¿Cuál es la diferencia entre aptitude y APT (Herramienta de empaquetado avanzada)?**

  * Aptitude es un administrador de paquetes de alto nivel, mientras que APT es un nivel inferior que puede ser utilizado por otros administradores de paquetes de nivel superior
  * Aptitude es más inteligente y eliminará automáticamente los paquetes no utilizados o sugerirá la instalación de paquetes dependientes
  * Apt solo hará explícitamente lo que se le indique en la línea de comando

5.**¿Qué es AppArmor?**

Sistema de seguridad Linux que proporciona seguridad de control de acceso obligatorio (MAC). Permite al administrador del sistema restringir las acciones que pueden realizar los procesos. Se incluye por defecto con Debian. Ejecute aa-status para verificar si se está ejecutando.

6.**Reglas de contraseña**

Para las reglas de contraseña, usamos la biblioteca de verificación de calidad de contraseña y hay dos archivos: el archivo de contraseña común que establece las reglas como mayúsculas y minúsculas, caracteres duplicados, etc. y el archivo login.defs que almacena las reglas de caducidad de la contraseña (30 días, etc.). Sudo nano /etc/login.defs Sudo nano /etc/pam.d/common-password

6.**¿Qué es LVM?**

Administrador de volumen lógico: nos permite manipular fácilmente las particiones o el volumen lógico en un dispositivo de almacenamiento.

7.**UFW (cortafuegos sin complicaciones)**
UFW es una interfaz para modificar el firewall del dispositivo sin comprometer la seguridad. Lo usa para configurar a qué puertos permitir conexiones y qué puertos cerrar. Esto es útil junto con SSH, puede establecer un puerto específico para que funcione.

8.**¿Qué es SSH?**

SSH o Secure Shell es un mecanismo de autenticación entre un cliente y un host. Utiliza técnicas de cifrado para que toda la comunicación entre clientes y hosts se realice de forma cifrada. El usuario en Mac o Linux puede usar SSH el terminal para trabajar en su servidor a través de SSH.

9.**¿Qué es Cron?**

Cron o trabajo cron es una utilidad de línea de comandos para programar comandos o secuencias de comandos para que sucedan en intervalos específicos o en un momento específico cada día. Útil si desea configurar su servidor para que se reinicie a una hora específica cada día.

## Comandos de evaluación para UFW, Group, Host, lsblk y SSH
* ```sudo ufw status```
* ```sudo systemctl status ssh```
* ```getent group sudo```
* ```getent group user42```
* ```sudo adduser new username```
* ```sudo groupadd groupname```
* ```sudo usermod -aG groupname username```
* ```sudo chage -l [name]``` verificar las reglas de caducidad de la contraseña
* ```hostnamectl```
* ```hostnamectl set-hostname new_hostname``` para cambiar el nombre de host actual
* Reinicie su máquina virtual.
* ```sudo nano /etc/hosts``` cambiar el nombre de host actual a un nuevo nombre de host
* ```lsblkpara``` mostrar las particiones
* ```dpkg -l | grep sudo``` para mostrar que sudo está instalado
* ```sudo ufw status numbered```
* ```sudo ufw allow port-id```
* ```sudo ufw delete rule number```
* ```ssh your_user_id@127.0.0.1 -p 4242``` haga esto en la terminal para mostrar que SSH al puerto 4242 está funcionando

--------------------------------------------------------------------
--------------------------------------------------------------------

## English

###tty

* to know that we are connected ```tty```

### hostnamectl

* view info: ```hostnamectl```
* to change the hostname: ```hostnamectl set-hostname [name]```
* * Restart your virtual machine.
* * sudo nano /etc/hosts

### Users
* view users: ```cat /etc/passwd```
* view users: ```getent passwd```
* new user: ```sudo adduser [name]```
* delete user: ```sudo userdel -r [name]```
* add user to a group: ```sudo usermod -aG [group_name] [user_name]```
#### password
* * to see policies ```chage -l [user]```
* * view or modify password policy ```sudo nano /etc/pam.d/common-password```


### Groups
* view groups: ```getent group```
* delete groups: ```sudo groupdel [name]```
* see the users that belong: ```getent group ssh```

### system

* SSH Port: ```sudo grep Port /etc/ssh/sshd_config```
* Check the operating system: ```head -n 2 /etc/os-release```
* Virtual machine disk partition: ```lsblk```
#### sudo
* * Check sudo: ```su -```
* * see the /etc/sudoers: ```sudo vim /etc/sudoers```

### ports
* see ports ```ss -tunlp```

### apparmor

* Check apparmor
* * cousin in sudo ```sudo su -```
* * check apparmor ```/usr/sbin/aa-status```

### chron

* Status : ```sudo systemctl status cron```
* Restart cron : ```sudo systemctl restart cron```
* Access the cron script: ```sudo crontab -u root -e```

----

----
### Defense with answers

1.**Why did I choose Debian?**

Easier to install and configure, making it better for personal servers.

2.**Difference between Debian and CentOS?**

Debian is much easier to upgrade than CentOS when a new version is released. Debian is easier to use and supports many libraries, file systems, and architecture. It also has more customization options. If you're a larger company, CentOS offers more business features and excellent support for business software.

3.**What is a Virtual Machine?**

It is a resource that uses software instead of a physical computer to run programs or applications. Each VM has its own separate operating system and features, so you can have more than one VM per machine. It can be used to test applications in a separate, secure environment. It works by using software to simulate virtual hardware and run on a host machine.

4.**What is the difference between aptitude and APT (Advanced Packaging Tool)?**

  * Aptitude is a high level package manager, while APT is a lower level that can be used by other higher level package managers
  * Aptitude is smarter and will automatically remove unused packages or suggest installing dependent packages
  * Apt will only explicitly do what it is told to do on the command line

5.**What is AppArmor?**

Linux security system that provides mandatory access control (MAC) security. Allows the system administrator to restrict the actions that processes can perform. It is included by default with Debian. Run aa-status to check if it is running.

6.**Password Rules**

For password rules, we use the password quality check library and there are two files: the common password file which sets the rules like case, duplicate characters, etc. and the login.defs file that stores the password expiration rules (30 days, etc.). sudo nano /etc/login.defs sudo nano /etc/pam.d/common-password

6.**What is LVM?**

Logical Volume Manager: It allows us to easily manipulate the partitions or the logical volume on a storage device.

7.**UFW (Uncomplicated Firewall)**
UFW is an interface to modify the device's firewall without compromising security. You use it to configure which ports to allow connections to and which ports to close. This is useful in conjunction with SSH, you can set a specific port for it to work on.

8.**What is SSH?**

SSH or Secure Shell is an authentication mechanism between a client and a host. It uses encryption techniques so that all communication between clients and hosts is encrypted. User on Mac or Linux can use SSH terminal to work on your server via SSH.

9.**What is Cron?**

Cron or cron job is a command line utility for scheduling commands or scripts to happen at specific intervals or at a specific time each day. Useful if you want to set your server to restart at a specific time each day.

## Test Commands for UFW, Group, Host, lsblk and SSH
* ```sudo ufw status```
* ```sudo systemctl status ssh```
* ```getent group sudo```
* ```getent group user42```
* ```sudo adduser new username```
* ```sudo groupadd groupname```
* ```sudo usermod -aG groupname username```
* ```sudo chage -l [name]``` check password expiration rules
* ```hostnamectl```
* ```hostnamectl set-hostname new_hostname``` to change the current hostname
* Restart your virtual machine.
* ```sudo nano /etc/hosts``` change the current hostname to a new hostname
* ```lsblk to ``` show partitions
* ```dpkg -l | grep sudo``` to show that sudo is installed
* ```sudo ufw status numbered```
* ```sudo ufw allow port-id```
* ```sudo ufw delete rule number```
* ```ssh your_user_id@127.0.0.1 -p 4242``` do this in terminal to show that SSH to port 4242 is working

-------------------------------------------------- ------------------
-------------------------------------------------- ------------------