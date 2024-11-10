# Description: Nginx Dockerfile

# Pull the base image from Docker Hub, using Debian Bullseye as the foundation for the Nginx server
FROM debian:bullseye

# Update the package list and upgrade any existing packages to ensure the system is up to date
RUN apt-get update && apt-get upgrade -y

# Install Nginx and OpenSSL packages. Nginx is the web server, and OpenSSL is used for creating SSL certificates
RUN apt-get install -y nginx openssl

# Create a directory for storing SSL certificates, ensuring the path exists
RUN mkdir -p /etc/nginx/ssl

# Generate a self-signed SSL certificate. The certificate will be used for HTTPS connections
# The command specifies the output file names and subject details for the certificate
RUN openssl req -x509 -nodes -out /etc/nginx/ssl/inception.crt -keyout \
    /etc/nginx/ssl/inception.key -subj "/C=NL/ST=NH/L=AMS/O=42/OU=CODAM/CN=juvan-to.42.fr/UID=Julia"

# Copy the Nginx configuration file from the host to the container. This configures how Nginx will behave
COPY ./conf/nginx.conf /etc/nginx/nginx.conf

# Create a directory for WordPress files that Nginx will serve
RUN mkdir -p /var/www/wordpress

# Change the ownership of the WordPress directory to the 'www-data' user and group
# This ensures that Nginx can access and serve files from this directory
RUN chown -R www-data:www-data /var/www/wordpress

# Define the default command to run when the container starts. This starts Nginx and keeps it running in the foreground
CMD ["nginx", "-g", "daemon off;"]
