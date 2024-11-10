# Description: MariaDB Dockerfile

# Specify the base image to use for the container.
FROM debian:bullseye

# Update the package lists for upgrades and install the latest versions of packages
RUN apt-get update && apt-get upgrade -y

# Install necessary packages: the MariaDB server and a text editor (nano)
RUN apt-get install -y mariadb-server nano

# Copy the MariaDB configuration file from the host to the specified directory in the container
COPY ./conf/50-server.cnf /etc/mysql/mariadb.conf.d/

# Change the permissions of the copied configuration file to ensure it is readable by the MariaDB server
RUN chmod 644 /etc/mysql/mariadb.conf.d/50-server.cnf

# Copy a shell script from the host to the root of the container's filesystem
COPY ./tools/mdb_conf.sh /mdb_conf.sh

# Make the copied shell script executable
RUN chmod +x /mdb_conf.sh

# Set the default command to run when the container starts, which in this case is the shell script
ENTRYPOINT ["./mdb_conf.sh"]

# Declare a mount point with the specified path, which allows data to persist across container restarts
VOLUME ["/var/lib/mysql"]

# Expose port 3306, which is the default port for MariaDB, allowing it to be accessed from outside the container
EXPOSE 3306
