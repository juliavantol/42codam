# Description: WordPress Dockerfile

# Use Debian Bullseye as the starting point for the image
FROM debian:bullseye

# Update the list of packages and get the latest versions
RUN apt-get update && apt-get install -y

# Install the packages needed to run WordPress
# These include tools and PHP with its necessary extensions
RUN apt-get install -y		\
			wget			\
			bash			\
			curl			\
			php				\
			php7.4-fpm		\
			php-mysql		\
			mariadb-client	\
			netcat

# Copy the WordPress setup script from your computer to the container
COPY ./conf/wp_conf.sh /

# Make the setup script executable, so it can run when the container starts
RUN chmod +x wp_conf.sh

# Set up a folder for WordPress files. This keeps the data safe even if the container restarts
VOLUME ["/var/www/wordpress"]

# Run the setup script when the container starts. This configures WordPress
ENTRYPOINT ["./wp_conf.sh"]

# Open port 9000 so that web traffic can reach the PHP service
EXPOSE 9000
