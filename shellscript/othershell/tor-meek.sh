#!/bin/bash
#    File Name: tor-meek.sh
#       Author: Johnny
#        Email: ligelaige@gmail.com
# Created Time: Wed 09 Sep 2015 08:11:23 PM CST

tor='/opt/tor-browser_en-US/Browser/TorBrowser/Tor/tor'
default_torrc='/opt/tor-browser_en-US/Browser/TorBrowser/Data/Tor/torrc-defaults'
file_torrc='/opt/tor-browser_en-US/Browser/TorBrowser/Data/Tor/torrc'
data_dir='/opt/tor-browser_en-US/Browser/TorBrowser/Data/Tor'
geo_ip_file='/opt/tor-browser_en-US/Browser/TorBrowser/Data/Tor/geoip'
geo_ipv6_file='/opt/tor-browser_en-US/Browser/TorBrowser/Data/Tor/geoip6'

tor_meek="$tor --defaults-torrc $default_torrc -f $file_torrc DataDirectory $data_dir GeoIPFile $geo_ip_file GeoIPv6File $geo_ipv6_file"

echo $tor_meek
$tor_meek
