#!/usr/bin/env bash
##########################################################
# Set the working directory path as the file path
cd "$(dirname "$0")"
bash runCMake.sh
cd ..
##########################################################

# Directory to store the results
results_dir="docs"

# Execute the entire test suite and save results to XML
output_xml="$results_dir/results_all_tests.xml"
out/bin/my_tests --gtest_output=xml:$output_xml

# Check if xsltproc is installed
if command -v xsltproc &> /dev/null; then
    echo "Converting $output_xml to HTML..."
    # Convert XML to HTML using xsltproc
    xsltproc -o "$results_dir/output_all_tests.html" "$results_dir/style/googleTestStyleSheet.xsl" $output_xml
    # Remove the XML file after conversion
    rm $output_xml
else
    echo "xsltproc is not installed. Skipping XML to HTML conversion."
fi
