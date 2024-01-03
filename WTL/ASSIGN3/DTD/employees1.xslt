<?xml version="1.0" encoding="UTF-8"?>
<xsl:stylesheet version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform">
    
    <xsl:template match="/">
        <html>
            <head>
                <style>
                    body {
                    font-family: Arial, sans-serif;
                    }
                    
                    h2 {
                    color: #333;
                    }
                    
                    table {
                    border-collapse: collapse;
                    width: 100%;
                    margin-top: 20px;
                    }
                    
                    th, td {
                    border: 1px solid #ddd;
                    padding: 12px;
                    text-align: left;
                    }
                    
                    th {
                    background-color: #3498db; /* Blue color */
                    color: #fff; /* White text */
                    font-weight: bold;
                    }
                    
                    tr:nth-child(even) {
                    background-color: #f9f9f9;
                    }
                </style>
            </head>
            <body>
                <h2>Employee Information</h2>
                <table>
                    <tr>
                        <th>ID</th>
                        <th>Name</th>
                        <th>Position</th>
                        <th>Department</th>
                        <th>Salary</th>
                    </tr>
                    <xsl:for-each select="employees1/employee">
                        <tr>
                            <td><xsl:value-of select="id"/></td>
                            <td><xsl:value-of select="name"/></td>
                            <td><xsl:value-of select="position"/></td>
                            <td><xsl:value-of select="department"/></td>
                            <td><xsl:value-of select="salary"/></td>
                        </tr>
                    </xsl:for-each>
                </table>
            </body>
        </html>
    </xsl:template>
    
</xsl:stylesheet>
