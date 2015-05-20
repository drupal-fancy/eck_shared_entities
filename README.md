# ECK Shared Entities

# Introduction

Current Maintainers:

* [axe312](https://www.drupal.org/u/axe312)

ECK Shared Entities extends Entity types created via with a share functionality.

This means, that user can flag entities as reusable and select these in a entity reference field as existing entity.
 
# This module provides

* ECK properties:
  * Shared entity flag - When this checkbox is checked, the entity can be found
  * Shared entity title - Users can provide an alternative title for the entity to make it easier to find. This is especially useful when the references entities do not have a title at all.

* Entityreference selection handler - This handler only lists shared entities and also allows the user to search for the shared entity title property in the autocomplete 

* Permissions granulated down to the entity bundle types

* Views support is provided by ECK

# Installation

1. Install the module the [drupal way](http://drupal.org/documentation/install/modules-themes/modules-7).

2. Enable the *Shared Entity Flag* and *Shared Entity Title* properties for your entity type. (/admin/structure/entity-type/[YOUR_TYPE]/properties)

3. Go to your Entity Reference field settings and select *Only shared entities* as entity selection mode.

4. When you use Inline Entity Form, you should ensure that *Allow users to add existing sections.* is enabled. The autocomplete matching setting is completely supported.

5. Go to the permissions page and set the permissions to match your needs.
