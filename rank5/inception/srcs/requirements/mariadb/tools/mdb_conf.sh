#!/bin/bash

#--------------mariadb start--------------#
service mariadb start  # Start the MariaDB service to allow it to begin accepting connections
sleep 15  # Pause for 5 seconds to ensure that MariaDB has enough time to start up fully

#--------------mariadb config--------------#
# Create a new database if it doesn't already exist
mariadb -e "CREATE DATABASE IF NOT EXISTS \`${MYSQL_DB}\`;"

# Create a new user if they do not already exist, using the environment variables for username and password
mariadb -e "CREATE USER IF NOT EXISTS \`${MYSQL_USER}\`@'%' IDENTIFIED BY '${MYSQL_PASSWORD}';"

# Grant all privileges on the specified database to the created user, allowing them to perform any action on it.
mariadb -e "GRANT ALL PRIVILEGES ON ${MYSQL_DB}.* TO \`${MYSQL_USER}\`@'%';"

# Apply the changes made to user privileges, ensuring that they take effect immediately.
mariadb -e "FLUSH PRIVILEGES;"

#--------------mariadb restart--------------#
# Shut down the MariaDB service to apply the new user and database configurations.
mysqladmin -u root -p"${MYSQL_ROOT_PASSWORD}" shutdown

# Restart the MariaDB service in a safe mode with specified options:
# - Run in the background to keep the container active.
# - Use port 3306 for connections.
# - Bind to all network interfaces to accept connections from any address.
# - Use the specified data directory for database files.
mysqld_safe --port=3306 --bind-address=0.0.0.0 --datadir='/var/lib/mysql'
